#include <stdio.h>
#include <stdlib.h>

#define REGULAR (1 << 0)
#define ESPRESSO (1 << 1)
#define DOUBLE_ESPRESSO (1 << 2)
#define MILK (1 << 3)
#define CREAM (1 << 4)
#define SOY (1 << 5)
#define SUGAR (1 << 6)
#define ARTIFICIAL (1 << 7)

struct coffee{
	int id;
	char property;	
};

void set_coffee_property(struct coffee* c, int property){
	c->property = c->property | property;
}

void unset_coffee_property(struct coffee* c, int property){
	c->property = c->property ^ property;
}

int main(){

	struct coffee* cof = (struct coffee*)malloc(sizeof(struct coffee));
	if(cof == NULL){
		// bad alloc
		exit(1);
	}
	cof->property = 0;
	cof->id = 0;

	set_coffee_property(cof, REGULAR | MILK | SUGAR);
	printf("%d\n", cof->property);
	unset_coffee_property(cof, MILK);
	printf("%d\n", cof->property);
	set_coffee_property(cof, CREAM);
	printf("%d\n", cof->property);

	return 0;
}
