FROM gcc:latest
RUN apt-get update && apt-get install -y make
WORKDIR /app
COPY . .
RUN make
CMD ["./ft_printf"]