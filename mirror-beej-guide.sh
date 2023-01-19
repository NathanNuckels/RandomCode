# Mirrors 'Beej's guide to network programing' in a docker container
# All programming documentation is blocked on wifi. This is a bad, but funtional solution.
curl http://beej.us/guide/bgnet/html>index.html
docker create -v .:/usr/share/nginx/html:ro -p 8000:80 nginx
