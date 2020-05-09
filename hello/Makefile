.PHONY = build cli

build:
	docker run -it --rm -v ${PWD}:/usr/src/ maciekbaron/sgdk:latest /usr/src/build.sh

cli:
	docker run -it --rm -v ${PWD}:/usr/src/ maciekbaron/sgdk:latest sh
