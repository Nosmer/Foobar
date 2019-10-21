#docker build -t name .
#creates a name image with Dockerfile in the current directory
#docker run -it --rm name
#runs a container using name image, deletes on exit
FROM alpine
RUN apk update && apk upgrade
RUN apk add vim

ENTRYPOINT vim
