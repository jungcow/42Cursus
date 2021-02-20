#! /bin/bash

cd /

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=InnovationAcademy/OU=42SEOUL/CN=localhost" -keyout localhost.key -out localhost.crt
mv localhost.key /etc/ssl/private
mv localhost.crt /etc/ssl/certs
chmod 600 /etc/ssl/private/localhost.key /etc/ssl/certs/localhost.crt


# nginx 설정
rm -rf /etc/nginx/sites-available/default
rm -rf /etc/nginx/sites-enabled/default
cp -p /tmp/srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf
# sites-available 폴더는 단지 설정을 적어두는 용도 - 적용이 안된다.
# 적용을 시켜줄려면 sites-enabled 폴더에 넣어두어야 하기 때문에 적용할 설정 파일만 sites-enabled에 넣어두고 심볼릭 링크를 걸어두는 것이다.

# 도메인 루트 설정
cp -rp /tmp/srcs/momontum /var/www/html/momontum
rm -rf /var/www/html/index.nginx-debian.html

service nginx start
service php7.3-fpm start

# install phpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz

# /var/www/html/로 압축 해제 후에 .tar.gz 파일 삭제
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz -C /var/www/html
rm -rf *.tar.gz

# phpmyadmin으로 이름 변경 -> 편할려고
# logindb로 symbolic link를 html폴더에 생성 -> phpmyadmin으로 쉽게 접속하는 것을 방지하기 위해
mv /var/www/html/phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin

# blowfish를 넣은 config 파일을 넣어준다.
# config.sample.inc.php -> config.inc.php로 이름 바꿔줘야 해당 설정파일이 적용됨.
cp -p /tmp/srcs/config.inc.php ./phpmyadmin/config.inc.php

service mysql start

# .sql 파일을 이용하여 mysql 실행
cp -p /tmp/srcs/init.sql /var/www/html/phpmyadmin/sql/init.sql
mysql < var/www/html/phpmyadmin/sql/create_tables.sql
mysql < var/www/html/phpmyadmin/sql/init.sql

# wordpress 설치
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv /wordpress/ /var/www/html

# wordpress의 소유자 변경 - wp-config.php를 작성 및  넣어주기 위해.
chown -R www-data:www-data /var/www/html/wordpress
cp -p /tmp/srcs/wp-config.php /var/www/html/wordpress/wp-config.php

service nginx restart
service php7.3-fpm restart
service mysql restart

bash
