#include <iostream>

class Dog {  // Soyut hedef
public:
	virtual ~Dog() = default;
	virtual void performsConversion() const = 0;
};

class DogFemale : public Dog {  // Somut hedef
public:
	virtual void performsConversion() const override { std::cout << "Dog female performs conversion." << std::endl; }
};

class Cat {  // Soyut ba�da�t�r�c�(adapter)
public:
	virtual ~Cat() = default;
	virtual void performsConversion() const = 0;
};

class CatFemale : public Cat {  // Somut ba�da�t�r�c�(adapter)
public:
	virtual void performsConversion() const override { std::cout << "Cat female performs conversion." << std::endl; }
};

class DogNature {
public:
	void carryOutNature(Dog* dog) {
		std::cout << "On with the Dog nature!" << std::endl;
		dog->performsConversion();
	}
};

class ConversionAdapter : public Dog {  // Ba�da�t�r�c�(Adapter)
private:
	Cat* cat;
public:
	ConversionAdapter(Cat* c) : cat(c) {}
	virtual void performsConversion() const override { cat->performsConversion(); }
};

int main() {  // Client code
	DogFemale* dogFemale = new DogFemale;
	CatFemale* catFemale = new CatFemale;
	DogNature dogNature;
	ConversionAdapter* adaptedCat = new ConversionAdapter(catFemale);  // catFemale dog olmaya adapte oldu

	dogNature.carryOutNature(dogFemale);
	dogNature.carryOutNature(adaptedCat);  //catFemale, adapte adaptedCat formunda, dogNature'a kat�l�yor
				// catFemale'in dogNature'da kendi do�as�n� ger�ekle�tirdi�ini unutmay�n.

	delete adaptedCat;  
	delete catFemale; 
	delete dogFemale; 
	return 0;
}