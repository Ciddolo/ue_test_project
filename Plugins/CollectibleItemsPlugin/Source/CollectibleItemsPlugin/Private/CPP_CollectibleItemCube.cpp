#include "CPP_CollectibleItemCube.h"

ACPP_CollectibleItemCube::ACPP_CollectibleItemCube()
{
	// Set a simple cube to the static mesh

	ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	StaticMesh->SetStaticMesh(Cube.Object);

	// Set a value to Points

	Points = 20;
}
