FROM ruby

RUN apt-get update -y; apt-get install sqlite3 -y
RUN gem update; gem install rails

COPY app /opt/app
WORKDIR /opt/app

ONBUILD RUN bundler install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
