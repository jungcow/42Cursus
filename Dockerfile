FROM debian:buster

RUN apt update \
		&& apt -y upgrade \
		&& apt -y install \
		nginx \
		php7.3 \
		php-fpm \
		php-mysql \
		mariadb-server \
		wget

COPY ./srcs/ /tmp/srcs

WORKDIR /tmp/srcs

CMD ["bash", "init.sh"]
