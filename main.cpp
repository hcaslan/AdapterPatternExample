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

class Cat {  // Soyut bağdaştırıcı(adapter)
public:
	virtual ~Cat() = default;
	virtual void performsConversion() const = 0;
};

class CatFemale : public Cat {  // Somut bağdaştırıcı(adapter)
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

class ConversionAdapter : public Dog {  // Bağdaştırıcı(Adapter)
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
	dogNature.carryOutNature(adaptedCat);  //catFemale, adapte adaptedCat formunda, dogNature'a katılıyor
				// catFemale'in dogNature'da kendi doğasını gerçekleştirdiğini unutmayın.

	delete adaptedCat;  
	delete catFemale; 
	delete dogFemale; 
	return 0;
}