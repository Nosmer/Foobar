FROM debian

RUN apt-get update; apt-get install curl openssh-server \
ca-certificates curl postfix
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install -y tzdata gitlab-ce
RUN apt-get clean && /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && sleep 2 && gitlab-ctl reconfigure && gitlab-ctl tail
