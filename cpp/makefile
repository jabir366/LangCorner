all: callback

callback: callback.cpp
	g++ -o output/callback callback.cpp
callback2: callback2.cpp
	g++ -o output/callback2 callback2.cpp

clean: 
	rm -rf output/*
clean-callback: 
	rm -rf output/callback
clean-callback2: 
	rm -rf output/callback2
myiter: myiter.cpp
	g++ -o output/myiter myiter.cpp
myset: myset.cpp
	g++ -o output/myset myset.cpp
myset2: myset2.cpp
	g++ -o output/myset2 myset2.cpp
vector: vector.cpp
	g++ -o output/vector vector.cpp
		output/vector
udp_client: udp_client.cpp
	g++ -g -o output/udp_client udp_client.cpp
		# output/udp_client
udp_server: udp_server.cpp
	g++ -o output/udp_server udp_server.cpp
		output/udp_server
inetpton: inetpton.cpp
	g++ -o output/inetpton inetpton.cpp
		output/inetpton
udp_clientv4v6: udp_clientv4v6.cpp
	g++ -o output/udp_clientv4v6 udp_clientv4v6.cpp
		output/udp_clientv4v6
strexp: strexp.cpp
	g++ -o output/strexp strexp.cpp -std=c++17
		output/strexp
structured_binding: structured_binding.cpp
	g++ -o output/structured_binding structured_binding.cpp -std=c++17
		output/structured_binding

