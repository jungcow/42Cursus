# ft_server
## ft_server 순서도
#### 1. debian:buster 이미지 설치 및 컨테이너 실행
#### 2. `apt install -y nginx php7.3 php-fpm` 명령어로 nginx 와 php7.3 과 php-fpm 설치
#### 3. /etc/nginx/sites-available/default 파일을 php와 연동 가능하게 수정
	```
        # pass PHP scripts to FastCGI server
        #
        location ~ \.php$ {
               include snippets/fastcgi-php.conf;
        #
        #       # With php-fpm (or other unix sockets):
               fastcgi_pass unix:/run/php/php7.3-fpm.sock;
        #       # With php-cgi (or other tcp sockets):
        #       fastcgi_pass 127.0.0.1:9000;
        }

        # deny access to .htaccess files, if Apache's document root
        # concurs with nginx's one
        #
        location ~ /\.ht {
               deny all;
        }
	```
	```
	    root /var/www/html;

        # Add index.php to the list if you are using PHP
        index index.html index.htm index.nginx-debian.html index.php; #index.php를 맨 마지막에 추가해줬다

        server_name _;

        location / {
                # First attempt to serve request as file, then
                # as directory, then fall back to displaying a 404.
                try_files $uri $uri/ =404;
        }
	```

- 위와 같이 주석 풀기 && index.php 추가해주기
#### 4. curl localhost 및 브라우저로 localhost 입력해서 들어가서 웹 서버와 php가 잘 연동 됐는지 확인하기
- /var/www/html/ 에 index.php를 다음과 같이 만들어두기 
```php
<?php phpinfo(); ?>
```
- `service nginx start` 와 `service php7.3-fpm`으로 먼저 실행을 시켜준다.
- local 머신에서 shell에 `curl localhost/index.php` 명령으로 웹서버와 php가 잘 연동되었는지 확인 가능하다.
#### 5. `wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz`으로 phpmyadmin 다운받는다.
- 그 이후 `tar -xvf php~`으로 압축해제해준다.
- /var/www/html/ 에 압축을 푼 폴더를 넣어준다.(도메인 폴더에 넣어준다.)
- 이름을 phpmyadmin으로 바꿔준다. -> localhost/phpmyadmin 으로 접속하기 위함

#### 6. phpmyadmin의 폴더 안의 config.sample.inc.php안에 blowfish 해시 암호를 넣어준다.
- blowfish 암호는 [blowfish generator](https://phpsolved.com/phpmyadmin-blowfish-secret-generator/?g=5cecac771c51c) 여기서 생성할 수 있다.
```
/**
 * This is needed for cookie based authentication to encrypt password in
 * cookie. Needs to be 32 chars long.
 */
$cfg['blowfish_secret'] = 'N;1Ze8p{XYfjHAzHWvMPQx:Y2SCFGsw6'; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */
```
#### 7. mysql 계정 생성 (유저와 비밀번호 생성)
```
mysqladmin -u root -p password # 입력 후 Enter password 가 뜨면 처음엔 비밀번호가 없으므로 바로 엔터를 눌러 다음에 나오는 비밀번호를 입력해준다. -> mysqladmin 을 쓰면 localhost root 계정만 비밀번호가 설정된다.

mysql -u root -p # 입력 후 나오는 커맨드 라인에 위에서 설정한 비밀번호를 입력해준다.

mysql> create user 'jungwkim'@'%' identified by '1234'; # 로 jungwkim 유저를 생성해준다.(비밀번호는 1234로 설정)

mysql> grant all privileges on *.* to 'jungwkim'@'%' identified by '1234' with grant option;
# -> grant all privileges 는 모든 권한을 승인해주겠다는 뜻. all privileges 대신 SELECT, UPDATE 등 이렇게 써줄 수 있다.
# -> on *.* 은 첫번째 * 이 database를 뜻하고 그다음 *이 테이블을 뜻한다. 따라서 위와 연결지어서 말하자면, 모든 데이터베이스 모든 테이블에 대하여 모든 권한을 승인해주겠다는 의미가 된다.
# -> to 'jungwkim'@'%' 은 jungwkim 유저에게 모든 host(내부 로컬 뿐만 아닌 외부 ip)로의 접근을 허용하겠다는 뜻이다.
# -> identified by '1234' 는 jungwkim 유저의 비밀번호를 넣어주어 권한을 바꿔준다.
# -> with grant option; 은 잘 모르겠다.
```
#### 8. wordpress 설치
- `wget https://wordpress.org/latest.tar.gz` 로 wordpress 설치
- `tar -xvf latest.tar.gz` 로 압축 해제 후 
	`mv wordpress/ var/www/html/` 로 경로 이동.
- `chown -R www-data:www-data /var/www/html/wordpress` 로 소유자 변경
	- wp-config.php 파일을 수정 및 생성을 위한 권한을 주기 위해서
	- wordpress GUI 서버를 통해 업로드 및 삭제를 하기 위해
	- [www-data란? 그리고 왜 사용해야 하는가?](https://www.python2.net/questions-787995.htm) 
	- 위 링크를 통해 좀더 알아가자.
	- www-data : 간단히 설명하자면, Ubuntu 의 웹서버(apache, nginx 등)가 기본적으로 일반 작업에 사용하는 사용자이다.
	- 왜 사용해야하는지? : 간단히 설명하자면, 웹서버 프로세스는 www-data 파일에 엑세스 할 수 있고, 이 외의 중요한 점은 없다고 한다.
	> Some web servers run as www-data. Web content should not be owned by this user, or a compromised web server would be able to rewrite a web site. Data written out by web servers will be owned by www-data.

#### 9. 

#### 9. wp-config-sample.php 를 작성한다.
	```php
		// ** MySQL settings - You can get this info from your web host ** //
		/** The name of the database for WordPress */
		define( 'DB_NAME', 'wordpress' );

		/** MySQL database username */
		define( 'DB_USER', 'jungwkim' );

		/** MySQL database password */
		define( 'DB_PASSWORD', '1234' );

		/** MySQL hostname */
		define( 'DB_HOST', 'localhost' );

		/** Database Charset to use in creating database tables. */
		define( 'DB_CHARSET', 'utf8' );

		/** The Database Collate type. Don't change this if in doubt. */
		define( 'DB_COLLATE', '' );
	```
#### 10. [localhost/wordpress](localhost/wordpress)로 접속하여 설정 모두 하기

#### 11. 설정 후에 보여주는 wp-config.php 내용들을 복사해서 wp-config-sample.php 의 위치에 넣어주기
#### 12. openssl 을 통해 ssl 인증서 발급 및 nginx 에 적용
#### 13. 



