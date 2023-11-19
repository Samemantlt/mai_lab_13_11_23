#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct {
	int value;
	int length;
} tSet;


bool set_equals(const tSet* set, const tSet* set2) {
	return set->length == set2->length && set->value == set2->value;
}

tSet set_by_index(const tSet set, int index, bool value) {
	tSet set2 = set;

	set2.value &= ~(1 << index);
	set2.value |= ((value ? 1 : 0) << index);

	return set2;
}



typedef struct {
	tSet symbols;
	bool badWord;
} tWord;

tWord word_empty() {
	tWord s = { 0, 0, 0 };
	return s;
}

bool words_good_and_not_equals(const tWord* a, const tWord* b) {
	if (a->badWord)
		return false;

	if (b->badWord)
		return false;

	return !set_equals(&(a->symbols), &(b->symbols));
}



bool isDelimiter(char symbol) {
	return symbol == ' ' || symbol == '\n' || symbol == '\t';
}



int main() {
	tWord lastWord = { 0, 0, true };
	tWord word = { 0, 0, 0 };

	long long count = 0;

	char current;
	bool previousCharIsDelimiter = false;

	while (scanf("%c", &current) != EOF)
	{
		if (isDelimiter(current)) {
			if (previousCharIsDelimiter) {
				continue;
			}

			if (words_good_and_not_equals(&lastWord, &word)) {
				count++;
			}

			lastWord = word;
			word = word_empty();
			previousCharIsDelimiter = true;
			continue;
		}

		previousCharIsDelimiter = false;

		if (!isalpha(current)) {
			word.badWord = true;
			continue;
		}

		if (!word.badWord) {
			word.symbols = set_by_index(word.symbols, current - 'a', true);
		}
	}

	if (words_good_and_not_equals(&lastWord, &word)) {
		count++;
	}

    // printf("Result: %lli\n", count);

	printf("Result: %s\n", count == 0 ? "not found" : "found");
}