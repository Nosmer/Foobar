FROM debian

ENV TS3SERVER_LICENSE=accept
RUN apt-get update -y
RUN apt-get install wget bzip2 -y
RUN wget http://dl.4players.de/ts/releases/3.8.0/teamspeak3-server_linux_amd64-3.8.0.tar.bz2
RUN tar xfvj teamspeak3-server_linux_amd64-3.8.0.tar.bz2
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /vat/tmp/*

ENTRYPOINT ["./teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
