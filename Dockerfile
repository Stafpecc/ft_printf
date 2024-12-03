FROM gcc:latest
RUN apt-get update && apt-get install -y make valgrind && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . /app
RUN make
RUN make test
CMD ["make", "install"]