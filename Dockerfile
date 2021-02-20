FROM	debian:buster

LABEL	maintainer="jungwkim@student.42seoul.kr" 

RUN apt update \
		&& apt -y upgrade \
		&& apt -y install \
		openssl \
		nginx \
		php7.3 \
		php-fpm \
		php-mysql \
		php-mbstring \
		mariadb-server \
		wget

EXPOSE 80 443

COPY ./srcs/ /tmp/srcs

WORKDIR /tmp/srcs

CMD ["bash", "init.sh"]
