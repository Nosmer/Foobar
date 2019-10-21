#docker build -t ex03 .
#docker run --name ex03 --it --rm -p 443:443 -p 80:80 -p 22:22 --privileged ex03
FROM debian

RUN apt-get update -y; apt-get install -y curl openssh-server \
ca-certificates postfix
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install -y tzdata gitlab-ce
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && sleep 2 && gitlab-ctl reconfigure && tail -f /dev/null
