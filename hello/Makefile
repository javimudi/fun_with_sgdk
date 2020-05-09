.PHONY = build cli

build:
	docker run -w /usr/src -it --rm -v ${PWD}:/usr/src/ maciekbaron/sgdk:latest /usr/src/build.sh

cli:
	docker run -w /usr/src -it --rm -v ${PWD}:/usr/src/ maciekbaron/sgdk:latest sh
