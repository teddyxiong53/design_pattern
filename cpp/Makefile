.PHONY: all clean prepare

CXXFLAGS += -std=c++11

prepare:
	if [ ! -e output ]; then \
		mkdir output; \
	fi

define compile_target
	g++ $(CXXFLAGS) $@.cpp -o output/$@
endef

01_SimpleFactory:
	$(compile_target)

02_FactoryMethod:
	$(compile_target)

03_AbstractFactory:
	$(compile_target)
clean:
	rm output -rf

