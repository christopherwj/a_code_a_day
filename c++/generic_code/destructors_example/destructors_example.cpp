#include <string>
#include <vector>

using namespace std;

class SkiLift
{
private:
	vector<string>* skiers_;

public:
	
	SkiLift() :
		skiers_(new vector<string>())
	{
	}

	~SkiLift()
	{
		delete skiers_;
	}

	void addSkier(const string& skier)
	{
		skiers_->push_back(skier);
	}

};

int main() {

	SkiLift chair;
	chair.addSkier("Tobias");
	chair.addSkier("Sarah");

	return 0;
}