.PHONY: all clean input output

all: input output check zip

input:
	# Put any data generation commands here
	bash make_curry_pancake.sh
	python3 generate_data.py
	cp handmade/* .

output: input
	bash ./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip
