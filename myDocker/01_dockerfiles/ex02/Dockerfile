#git clone adress app
#docker build -t ft-rails:on-build .
#docker build -t name -f Subject_Docker.
#docker run -it --rm -p 3000:3000 name
FROM ruby:2.5.1

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install nodejs postgresql-client -y
RUN apt-get clean && rm -rf f/var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY app /opt/app
WORKDIR /opt/app

ONBUILD WORKDIR /opt/app
ONBUILD RUN bundler install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
