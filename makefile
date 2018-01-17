default:
	rm -rf ./prog
	cd ./src && $(MAKE)

clean:
	rm -rf ./prog
	cd ./src && $(MAKE) clean
