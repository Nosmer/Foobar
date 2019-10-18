FROM ubuntu

EXPOSE 3000 27017 35729

RUN apt-get -q update && apt-get install -y -qq \
git curl ssh gcc make build-essential sudo apt-utils
RUN curl -sL https://deb.noderesource.com/setub_6.x | sudo -E bash - \
apt-get install -y -q nodejs
RUN npm install --quiet -g bower gulp
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
