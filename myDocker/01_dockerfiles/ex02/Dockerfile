FROM ruby

RUN apt-get update -y; apt-get install sqlite3 -y
RUN gem update; gem install rails
RUN apt-get clean && rm -rf f/var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY app /opt/app
WORKDIR /opt/app

ONBUILD RUN bundler install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
