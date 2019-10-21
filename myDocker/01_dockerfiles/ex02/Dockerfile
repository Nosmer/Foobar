#docker build -t name .
#run this in ft-rails directory first then dockerfile from the subject
#from OUTSIDE of the directory:
#docker build -t name -f Docker_subj .
FROM ruby

RUN apt-get update -y; apt-get install sqlite3 -y
RUN gem update; gem install rails
RUN apt-get clean && rm -rf f/var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY app /opt/app
WORKDIR /opt/app

EXPOSE 3000

ONBUILD RUN bundler install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
