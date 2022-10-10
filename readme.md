# Docker

```terminal
wsl

docker build -t adf-image .
docker run -it --rm -v ${PWD}:/develop adf-image
```