FROM debian

RUN apt-get update; apt-get install curl openssh-server \
ca-certificates curl postfix
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash

