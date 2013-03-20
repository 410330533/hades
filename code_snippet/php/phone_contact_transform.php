<?php

// quoted_printable_decode
// quoted_printable_encode
// m8 备份 xml 转换成 vcf
function transform_m8_xml_to_vcf($xml_filename, $vcf_filename)
{
    if ( ! file_exists($xml_filename)){
        echo sprintf('file %s not exists, please check', $xml_filename);
        return false;
    }
    
    $vcf_unit = "BEGIN:VCARD
    VERSION:2.1
    N:;%s;;;
    FN:%s
    TEL;CELL;PREF:%s
    TEL;CELL;:%s
    END:VCARD";
    $vcf_content = '';

    $xml = simplexml_load_file($xml_filename);
    foreach ($xml->Contact as $contact){
        $username = (string) $contact->FirstName;
        $vcf_content .= sprintf("BEGIN:VCARD\nVERSION:2.1\nN:;%s;;;\nFN:%s\n", $username, $username);
        
        $phone = $contact->Phone;
        foreach ($phone->children() as $phone_element){
            $isPrimary = false;
            $phone_number = '';
            foreach ($phone_element->attributes() as $key => $val){
                if ($key == 'IsPrimary'){
                    $isPrimary = (bool)(string) $val;
                    continue ;
                }
                
                if ($key == 'Value'){
                    $phone_number = str_replace('+86', '', trim($val));
                    continue ;
                }
            }
            $vcf_content .= sprintf("TEL;CELL;%s:%s\n", $isPrimary ? 'PREF' : '', $phone_number);
        }
        
        $vcf_content .= "END:VCARD\n";
    }

    file_put_contents($vcf_filename, $vcf_content);
}

// xmx 备份 xml 转换成 vcf
function transform_xmx_xml_to_vcf($xml_filename, $vcf_filename)
{
    if ( ! file_exists($xml_filename)){
        echo sprintf('file %s not exists, please check', $xml_filename);
        return false;
    }
    
    $vcf_unit = "BEGIN:VCARD
    VERSION:2.1
    N:;%s;;;
    FN:%s
    TEL;CELL;PREF:%s
    TEL;CELL;:%s
    END:VCARD";
    $vcf_content = '';

    $xml = simplexml_load_file($xml_filename);
    foreach ($xml->Contact as $contact){
        $username = (string) $contact->FirstName;
        $vcf_content .= sprintf("BEGIN:VCARD\nVERSION:2.1\nN:;%s;;;\nFN:%s\n", $username, $username);
        
        foreach ($contact->PhoneElement as $phone_element){
            $isPrimary = false;
            foreach ($phone_element->attributes() as $key => $val){
                if ($key == 'IsPrimary'){
                    $isPrimary = (bool)(string) $val;
                    continue ;
                }
                
                if ($key == 'Value'){
                    $phone_number = str_replace('+86', '', trim($val));
                    $phone_number = str_replace(['-', '+86'], ['', ''], (string) $val);
                    continue ;
                }
            }
            
            $vcf_content .= sprintf("TEL;CELL;%s:%s\n", $isPrimary ? 'PREF' : '', $phone_number);
        }
        $vcf_content .= "END:VCARD\n";
    }

    file_put_contents($vcf_filename, $vcf_content);
}

$xml_filename = 'Contact.xml';
$vcf_filename = 'Contact.vcf';
// transform_m8_xml_to_vcf($xml_filename, $vcf_filename);
transform_xmx_xml_to_vcf($xml_filename, $vcf_filename);