bank_sim: driver.o customer.o
	g++ -o bank_sim driver.o customer.o
driver.o: driver.cpp customer.cpp customer.h arrayqueue.h priorityqueue.h queue.h
	g++ -c driver.cpp customer.cpp
customer.o: customer.cpp customer.h
	g++ -c customer.cpp
arrayqueue.o: arrayqueue.cpp arrayqueue.h
	g++ -c arrayqueue.cpp
priorityqueue.o: priorityqueue.cpp priorityqueue.h
	g++ -c priorityqueue.cpp
clean:
	rm *.o bank_sim