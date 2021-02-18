#! /bin/bash

# /etc/nginx/sites-available/default 
# conf 파일들을 각자 위치에 넣기
cp -p /tmp/srcs/default /etc/nginx/sites-available/
cp -p /tmp/srcs/index.php /var/www/html/

# install phpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz

# /var/www/html/로 압축 해제 후에 .tar.gz 파일 삭제
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz -C /var/www/html
rm -rf *.tar.gz

# phpmyadmin으로 이름 변경 -> 편할려고
# logindb로 symbolic link를 html폴더에 생성 -> phpmyadmin으로 쉽게 접속하는 것을 방지하기 위해
cd /var/www/html
mv phpMyAdmin-5.0.2-all-languages phpmyadmin

# blowfish를 넣은 config 파일을 넣어준다.
# config.sample.inc.php -> config.inc.php로 이름 바꿔줘야 해당 설정파일이 적용됨.
cp -p /tmp/srcs/config.inc.php ./phpmyadmin/

service nginx start
service php7.3-fpm start
service mysql start

bash
