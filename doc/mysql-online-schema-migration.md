* Facebook OnlineSchemaChange
    * https://www.facebook.com/note.php?note_id=430801045932
    * https://github.com/facebookincubator/OnlineSchemaChange
    * https://github.com/facebookincubator/OnlineSchemaChange/wiki/Limitation
    ```
    osc_cli copy --socket=/var/run/mysqld/mysqld.sock --mysql-user=user --mysql-password=password --database=db --ddl-file-list=fb.sql
    osc_cli cleanup --socket=/var/run/mysqld/mysqld.sock --mysql-user=user --mysql-password=password --database=db
    ```
* Percona Tool kit
    * https://www.percona.com/doc/percona-toolkit/LATEST/pt-online-schema-change.html
    * https://help.aliyun.com/knowledge_detail/41734.html
    * apt-get install libdbd-mysql-perl
    ```
    ./pt-online-schema-change --alter "ADD column c2 varchar(30)" D=db,t=table,u=user,p=password --alter-foreign-keys-method=auto
    ```
    * alter CounterLog add column c2 varchar(30)
    ```
    Operation, tries, wait:
      analyze_table, 10, 1
      copy_rows, 10, 0.25
      create_triggers, 10, 1
      drop_triggers, 10, 1
      swap_tables, 10, 1
      update_foreign_keys, 10, 1
    Exiting without altering `oms_stress`.`CounterLog` because neither --dry-run nor --execute was specified.  Please read the tool's documentation carefully before using this tool.
    mahone@ubuntu:~/git/hades/software/percona-toolkit-3.0.3/bin$ ./pt-online-schema-change --alter "ADD column c2 varchar(30)" h=oms4b.uco.com,P=3001,D=oms_stress,t=CounterLog,u=root,p=12bedbba17fc8941b592df4af75a2ed0 --execute
    No slaves found.  See --recursion-method if host db-omsstress has slaves.
    Not checking slave lag because no slaves were found and --check-slave-lag was not specified.
    Operation, tries, wait:
      analyze_table, 10, 1
      copy_rows, 10, 0.25
      create_triggers, 10, 1
      drop_triggers, 10, 1
      swap_tables, 10, 1
      update_foreign_keys, 10, 1
    Altering `oms_stress`.`CounterLog`...
    Creating new table...
    Created new table oms_stress._CounterLog_new OK.
    Altering new table...
    Altered `oms_stress`.`_CounterLog_new` OK.
    2017-07-04T17:49:45 Creating triggers...
    2017-07-04T17:49:45 Created triggers OK.
    2017-07-04T17:49:45 Copying approximately 27524141 rows...
    Copying `oms_stress`.`CounterLog`:   7% 06:20 remain
    Copying `oms_stress`.`CounterLog`:  13% 06:10 remain
    Copying `oms_stress`.`CounterLog`:  20% 05:47 remain
    Copying `oms_stress`.`CounterLog`:  27% 05:15 remain
    Copying `oms_stress`.`CounterLog`:  35% 04:26 remain
    Copying `oms_stress`.`CounterLog`:  44% 03:42 remain
    Copying `oms_stress`.`CounterLog`:  53% 03:02 remain
    Copying `oms_stress`.`CounterLog`:  61% 02:33 remain
    Copying `oms_stress`.`CounterLog`:  68% 02:02 remain
    Copying `oms_stress`.`CounterLog`:  76% 01:32 remain
    Copying `oms_stress`.`CounterLog`:  84% 01:02 remain
    Copying `oms_stress`.`CounterLog`:  91% 00:33 remain
    Copying `oms_stress`.`CounterLog`:  99% 00:01 remain
    2017-07-04T17:56:56 Copied rows OK.
    2017-07-04T17:56:56 Analyzing new table...
    2017-07-04T17:56:56 Swapping tables...
    2017-07-04T17:56:56 Swapped original and new tables OK.
    2017-07-04T17:56:56 Dropping old table...
    2017-07-04T17:57:01 Dropped old table `oms_stress`.`_CounterLog_old` OK.
    2017-07-04T17:57:01 Dropping triggers...
    2017-07-04T17:57:01 Dropped triggers OK.
    Successfully altered `oms_stress`.`CounterLog`.

    real    6m47.060s
    user    0m0.712s
    sys     0m3.348s
    ```
    * alter SalesOrder add column c2 varchar(30) (foreign key)
    ```
    No slaves found.  See --recursion-method if host ubuntu has slaves.
    Not checking slave lag because no slaves were found and --check-slave-lag was not specified.
    Operation, tries, wait:
      analyze_table, 10, 1
      copy_rows, 10, 0.25
      create_triggers, 10, 1
      drop_triggers, 10, 1
      swap_tables, 10, 1
      update_foreign_keys, 10, 1
    Child tables:
      `oms_dev`.`BillableOrder` (approx. 1 rows)
      `oms_dev`.`ChanelSapOrder` (approx. 1 rows)
      `oms_dev`.`EsteeLauderReturnLog` (approx. 1 rows)
      `oms_dev`.`EsteeLauderSapLog` (approx. 1 rows)
      `oms_dev`.`EsteeLauderSapOrder` (approx. 1 rows)
      `oms_dev`.`Invoice` (approx. 8 rows)
      `oms_dev`.`MergeOrderMap` (approx. 1 rows)
      `oms_dev`.`MergeOrderRelation` (approx. 18 rows)
      `oms_dev`.`PaymentLine` (approx. 18 rows)
      `oms_dev`.`PrePromoteCache` (approx. 1 rows)
      `oms_dev`.`ReturnMerchandiseAuthorization` (approx. 1 rows)
      `oms_dev`.`SalesOrderAutoReverseHighlight` (approx. 1 rows)
      `oms_dev`.`SalesOrderLine` (approx. 36 rows)
      `oms_dev`.`SalesOrderRefund` (approx. 1 rows)
      `oms_dev`.`Shipment` (approx. 7 rows)
      `oms_dev`.`VirtualAccountLog` (approx. 35 rows)
      `oms_dev`.`Warehousing` (approx. 5 rows)
      `oms_dev`.`YhdOrderUpdateStatusLog` (approx. 1 rows)
    Will automatically choose the method to update foreign keys.
    Altering `oms_dev`.`SalesOrder`...
    Creating new table...
    Created new table oms_dev._SalesOrder_new OK.
    Altering new table...
    Altered `oms_dev`.`_SalesOrder_new` OK.
    2017-07-04T15:41:12 Creating triggers...
    2017-07-04T15:41:12 Created triggers OK.
    2017-07-04T15:41:12 Copying approximately 21 rows...
    2017-07-04T15:41:12 Copied rows OK.
    2017-07-04T15:41:12 Max rows for the rebuild_constraints method: 14266
    Determining the method to update foreign keys...
    2017-07-04T15:41:12   `oms_dev`.`BillableOrder`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`ChanelSapOrder`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`EsteeLauderReturnLog`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`EsteeLauderSapLog`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`EsteeLauderSapOrder`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`Invoice`: 8 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`MergeOrderMap`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`MergeOrderRelation`: 18 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`PaymentLine`: 18 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`PrePromoteCache`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`ReturnMerchandiseAuthorization`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`SalesOrderAutoReverseHighlight`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`SalesOrderLine`: 36 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`SalesOrderRefund`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`Shipment`: 7 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`VirtualAccountLog`: 35 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`Warehousing`: 5 rows; can use rebuild_constraints
    2017-07-04T15:41:12   `oms_dev`.`YhdOrderUpdateStatusLog`: 1 rows; can use rebuild_constraints
    2017-07-04T15:41:12 Analyzing new table...
    2017-07-04T15:41:12 Swapping tables...
    2017-07-04T15:41:12 Swapped original and new tables OK.
    2017-07-04T15:41:12 Rebuilding foreign key constraints...
    2017-07-04T15:41:12 Dropping old table...
    2017-07-04T15:41:12 Dropped old table `oms_dev`.`_SalesOrder_old` OK.
    2017-07-04T15:41:12 Dropping triggers...
    2017-07-04T15:41:12 Dropped triggers OK.
    ```
* GH-OST
    * https://github.com/github/gh-ost
    ```
    2017-07-07 15:41:15 INFO starting gh-ost 1.0.36
    2017-07-07 15:41:15 INFO Migrating `oms_dev`.`Config`
    2017-07-07 15:41:15 INFO connection validated on 127.0.0.1:3306
    2017-07-07 15:41:15 INFO User has ALL privileges
    2017-07-07 15:41:15 INFO 127.0.0.1:3306 has MIXED binlog_format. I will change it to ROW, and will NOT change it back, even in the event of failure.
    2017-07-07 15:41:15 INFO binary logs validated on 127.0.0.1:3306
    2017-07-07 15:41:15 INFO Restarting replication on 127.0.0.1:3306 to make sure binlog settings apply to replication thread
    2017-07-07 15:41:15 INFO Inspector initiated on ubuntu:3306, version 5.7.17-0ubuntu0.16.04.2-log
    2017-07-07 15:41:15 INFO Table found. Engine=InnoDB
    2017-07-07 15:41:22 INFO Estimated number of rows via EXPLAIN: 11
    2017-07-07 15:41:22 INFO Recursively searching for replication master
    2017-07-07 15:41:22 INFO Master found to be ubuntu:3306
    2017-07-07 15:41:22 WARNING log_slave_updates not found on 127.0.0.1:3306, but executing directly on master, so I'm proceeeding
    2017-07-07 15:41:22 INFO connection validated on 127.0.0.1:3306
    2017/07/07 15:41:22 binlogsyncer.go:75: [info] create BinlogSyncer with config &{99999 mysql 127.0.0.1 3306 mahone taobao  false false <nil>}
    2017-07-07 15:41:22 INFO Connecting binlog streamer at mysql-bin.000003:154
    2017/07/07 15:41:22 binlogsyncer.go:241: [info] begin to sync binlog from position (mysql-bin.000003, 154)
    2017/07/07 15:41:22 binlogsyncer.go:134: [info] register slave for master server 127.0.0.1:3306
    2017-07-07 15:41:22 INFO connection validated on 127.0.0.1:3306
    2017/07/07 15:41:22 binlogsyncer.go:568: [info] rotate to (mysql-bin.000003, 154)
    2017-07-07 15:41:22 INFO rotate to next log name: mysql-bin.000003
    2017-07-07 15:41:22 INFO connection validated on 127.0.0.1:3306
    2017-07-07 15:41:22 INFO will use time_zone='SYSTEM' on applier
    2017-07-07 15:41:22 INFO Examining table structure on applier
    2017-07-07 15:41:22 INFO Applier initiated on ubuntu:3306, version 5.7.17-0ubuntu0.16.04.2-log
    2017-07-07 15:41:22 INFO Droppping table `oms_dev`.`_Config_ghc`
    2017-07-07 15:41:22 INFO Table dropped
    2017-07-07 15:41:22 INFO Creating changelog table `oms_dev`.`_Config_ghc`
    2017-07-07 15:41:22 INFO Changelog table created
    2017-07-07 15:41:22 INFO Creating ghost table `oms_dev`.`_Config_gho`
    2017-07-07 15:41:23 INFO Ghost table created
    2017-07-07 15:41:23 INFO Altering ghost table `oms_dev`.`_Config_gho`
    2017-07-07 15:41:23 INFO Ghost table altered
    2017-07-07 15:41:23 INFO Intercepted changelog state GhostTableMigrated
    2017-07-07 15:41:23 INFO Waiting for ghost table to be migrated. Current lag is 0s
    2017-07-07 15:41:23 INFO Handled changelog state GhostTableMigrated
    2017-07-07 15:41:23 INFO Chosen shared unique key is PRIMARY
    2017-07-07 15:41:23 INFO Shared columns are id,name,value,remark,created,updated
    2017-07-07 15:41:23 INFO Listening on unix socket file: /tmp/gh-ost.oms_dev.Config.sock
    2017-07-07 15:41:23 INFO Migration min values: [10]
    2017-07-07 15:41:23 INFO Migration max values: [20]
    2017-07-07 15:41:23 INFO Waiting for first throttle metrics to be collected
    2017-07-07 15:41:23 INFO First throttle metrics collected
    # Migrating `oms_dev`.`Config`; Ghost table is `oms_dev`.`_Config_gho`
    # Migrating ubuntu:3306; inspecting ubuntu:3306; executing on ubuntu
    # Migration started at Fri Jul 07 15:41:15 +0800 2017
    # chunk-size: 1000; max-lag-millis: 1500ms; max-load: Threads_running=25; critical-load: Threads_running=1000; nice-ratio: 0.000000
    # throttle-additional-flag-file: /tmp/gh-ost.throttle
    # postpone-cut-over-flag-file: /tmp/ghost.postpone.flag
    # panic-flag-file: /tmp/ghost.panic.flag
    # Serving on unix socket: /tmp/gh-ost.oms_dev.Config.sock
    2017-07-07 15:41:23 INFO Row copy complete
    Copy: 0/11 0.0%; Applied: 0; Backlog: 0/100; Time: 7s(total), 0s(copy); streamer: mysql-bin.000003:2249; State: migrating; ETA: N/A
    Copy: 0/0 100.0%; Applied: 0; Backlog: 0/100; Time: 7s(total), 0s(copy); streamer: mysql-bin.000003:2249; State: migrating; ETA: due
    2017-07-07 15:41:23 INFO New table structure follows
    CREATE TABLE `_Config_gho` (
      `id` int(11) NOT NULL AUTO_INCREMENT,
      `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
      `value` longtext CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
      `remark` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
      `created` datetime NOT NULL,
      `updated` datetime NOT NULL,
      PRIMARY KEY (`id`),
      UNIQUE KEY `nameIndex` (`name`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8
    2017-07-07 15:41:23 INFO Closed streamer connection. err=<nil>
    2017-07-07 15:41:23 INFO Droppping table `oms_dev`.`_Config_ghc`
    2017-07-07 15:41:23 INFO Table dropped
    2017-07-07 15:41:23 INFO Droppping table `oms_dev`.`_Config_gho`
    2017-07-07 15:41:23 INFO Table dropped
    2017-07-07 15:41:23 INFO Done migrating `oms_dev`.`Config`
    2017-07-07 15:41:23 INFO Removing socket file: /tmp/gh-ost.oms_dev.Config.sock
    # Done
    ```