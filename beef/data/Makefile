.PHONY: all clean input output

all: input output check zip

input:
	# Put any data generation commands here
	python3 gen.py
	rm tkgen
	cp handmade/* .

output: input
	bash ./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip
