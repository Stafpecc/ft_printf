FROM debian:latest

WORKDIR /app

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gcc \
    make \
    git \
    && apt-get clean

COPY . /app/

RUN make test

CMD ["make", "test"]