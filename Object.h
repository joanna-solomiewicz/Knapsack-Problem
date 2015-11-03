#pragma once

class Object {
public:
	Object(int ordinal);
	Object(int ordinal, int value, int weight);

    int ordinal;
    int value;
    int weight;

};
