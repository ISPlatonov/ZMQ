FROM gcc:latest

RUN apt-get update && apt-get install -y cmake libboost-dev libzmq3-dev

COPY . /code

WORKDIR /code

EXPOSE 5555

CMD cmake CMakeLists.txt && \
    make && \
    make install && \
    build/publisher