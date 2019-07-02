# RPC Benchmark

Benchmark on different RPC implementations (grpc vs. thrift vs. ZeroMQ-based impl)

This project contains three single threaded rpc implementations on a simple *Echo* server. 

## Result

Unit: qps (request/second)

| RPC framework             |   1byte payload    | 4KiB payload | 128KiB payload | 
| :------------------------ |:-------------------|:-------------|:---------------|
| grpc                      |  12147.147         |   10888.508  |  3457.777      |
| grpc-async                |  12370.392         |   11080.590  |  3595.076      |
| thrift (FramedTransport)  |  50939.983         |   48373.127  |  10036.858     |
| thrift (BufferedTransport)|  54526.430         |   21457.006  |  1578.458      |
| ZeroMQ                    |  20917.171         |   19467.157  |  8390.608      |



## Test machine configuration

- CPU: Intel i7-4790 @ 3.60GHz
- Memory: 32GB
- OS: archlinux
- Network: loopback
- Kernel: 5.1.15
- Gcc version: 9.1.0
- grpc version: 1.21.4
- thrift version: 0.12.0
- ZeroMQ version: 4.3.1
