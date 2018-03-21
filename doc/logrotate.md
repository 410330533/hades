```
/path/to/logs/* {
    size 100M
    daily

    rotate 30
    compress
    delaycompress
    dateext

    missingok
    notifempty
    sharedscripts
    postrotate
        xxxxxxxxxxx
    endscript
}
```

