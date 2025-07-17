#include <stdlib.h> // for malloc
#include <string.h>
#include <stdio.h>

typedef struct Str {
	int bytes;	// Does not count the \0
	char* data;
} Str;

Str str(char* init) {
	int len = strlen(init); 
	char* data = malloc(len + 1);
	strcpy(data, init);
	Str s = { len, data };
	return s;
}

Str concat(Str s1, Str s2) {
	int new_length = s1.bytes + s2.bytes;
	char* new_data = malloc(new_length + 1);
	strcpy(new_data, s1.data);
	strcpy(new_data + s1.bytes, s2.data);
	Str new_str = { new_length, new_data };
	return new_str;
}

Str join(Str delim, Str strs[], int size) {
	Str result = str("");
	// high-level strategy: use concat() in a for loop
	for(int i = 0; i < size; i += 1) {
		char* before = result.data;
		result = concat(result, strs[i]);
		free(before);
		if(i < size - 1) {
			before = result.data;
			result = concat(result, delim);
			free(before);
		}
	}
	return result;
}

int main() {
	Str abc = str("abc");
	Str def = str("def");
	Str result = concat(abc, def);
	printf("%s %d\n", result.data, result.bytes);

	// How to write a test for join()?
	// join(str(","), {str("hello"), str("world")]) —> str("hello, world")
	// join(str(","), {str("a"), str("b"), str("c")}) -> str("a,b,c")
	Str strs[] = { str("hello"), str("world") };
	Str comma = str(",");
	Str result2 = join(comma, strs, 2);
	printf("Should be hello,world: %s %d\n", result2.data, result2.bytes);
	
	Str abcd[] = { str("a"), str("b"), str("c"), str("d") };
	Str dash = str("-");
	Str abcd_result = join(dash, abcd, 4);
	printf("Expect a-b-c-d: %s %d\n", abcd_result.data, abcd_result.bytes);
	free(abc.data);
	free(def.data);
	free(result.data);
	free(strs[0].data); free(strs[1].data);
	free(result2.data);
	free(abcd[0].data); free(abcd[1].data);
	free(abcd[2].data); free(abcd[3].data);
	free(abcd_result.data);
	free(comma.data); free(dash.data);
}

