#include "CPP_CollectibleItemSphere.h"

ACPP_CollectibleItemSphere::ACPP_CollectibleItemSphere()
{
	// Set a simple sphere to the static mesh

	ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("/Game/StarterContent/Shapes/Shape_Sphere"));
	StaticMesh->SetStaticMesh(Sphere.Object);

	// Set a value to Points

	Points = 10;
}
