ifconfig | grep ether | cut -d " " -f 2 | sed '2d'
