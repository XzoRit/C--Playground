// Techniken.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <functional>
#include "BabylogC\app\LicenseHandling\CommandDispatcher\Descriptor\ProductLicenseTypeContainer.h"

static BabylogC::ProductLicenseTypeContainer::ProductLicenseId sProdLicId;

bool prodLicIdEqual(const BabylogC::ProductLicenseTypeContainer::ProductLicenseId& prodLicId)
{
	return ((sProdLicId.header == prodLicId.header) &&
		(sProdLicId.identification == prodLicId.identification));
}

struct check : std::unary_function<BabylogC::ProductLicenseTypeContainer::ProductLicenseId, bool>
{
	bool operator()(const BabylogC::ProductLicenseTypeContainer::ProductLicenseId& prodLic)
	{
		return ((sProdLicId.header == prodLic.header) &&
			(sProdLicId.identification == prodLic.identification));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	BabylogC::ProductLicenseTypeContainer::ProductLicenseIdContainer prodLicIds;

	BabylogC::ProductLicenseTypeContainer::ProductLicenseId extendedScreenConfig = {0x0109, 0x3015201b};
    BabylogC::ProductLicenseTypeContainer::ProductLicenseId aprv = {0x0109, 0x30152012};
    BabylogC::ProductLicenseTypeContainer::ProductLicenseId atc = {0x0109, 0x30152011};
    BabylogC::ProductLicenseTypeContainer::ProductLicenseId afVgMmvVs = {0x0109, 0x3015200D};
    BabylogC::ProductLicenseTypeContainer::ProductLicenseId trends = {0x0109, 0x30152019};
    BabylogC::ProductLicenseTypeContainer::ProductLicenseId evitaLargeConfig = {0x109, 0x30152025};

	prodLicIds.push_back(extendedScreenConfig);
	prodLicIds.push_back(aprv);
	prodLicIds.push_back(atc);
	prodLicIds.push_back(afVgMmvVs);
	prodLicIds.push_back(trends);
	prodLicIds.push_back(evitaLargeConfig);

	::sProdLicId = extendedScreenConfig;

	if(prodLicIds.end() != find_if(prodLicIds.begin(), prodLicIds.end(), check()))
	{
		std::cout << "extendedScreenConfig found!";
	}
	else
	{
		std::cout << "extendedScreenConfig not found!!!";
	}

	return 0;
}

