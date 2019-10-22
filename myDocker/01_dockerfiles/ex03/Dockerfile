#docker build -t name .
#docker run -it --rm -p 8443:443 -p 8080:80 -p 8022:22 --privileged name
#docker-exec -it [container_name] sh
FROM debian

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y wget openssh-server ca-certificates \
postfix
RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 ./script.deb.sh && ./script.deb.sh
RUN apt-get install -y tzdata gitlab-ce -y
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && sleep 2 && gitlab-ctl reconfigure && gitlab-ctl tail
