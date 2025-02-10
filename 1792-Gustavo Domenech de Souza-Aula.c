typedef struct{
    int pass;
    int total;
} Class;

double calculateBenefit( int pass, int total ){
    double currentRatio = (double)pass / total;
    double newRatio = (double)(pass + 1) / (total + 1);
    return newRatio - currentRatio;
}

int compare( const void* a, const void* b ){
    Class* classA = ( Class* )a;
    Class* classB = ( Class* )b;
    double benefitA = calculateBenefit( classA -> pass, classA -> total );
    double benefitB = calculateBenefit( classB -> pass, classB -> total );
    if ( benefitA < benefitB ){
        return 1;
    }
    if ( benefitA > benefitB ){
        return -1;
    }
    return 0;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {

Class *heap = ( Class* )malloc(classesSize * sizeof(Class));

int i;

for( i = 0; i < classesSize; i++){
    heap[i].pass = classes[i][0];
    heap[i].total = classes[i][1];
} 

qsort(heap, classesSize, sizeof(Class), compare);

for( i = 0; i < extraStudents; i++ ){
    heap[0].pass += 1;
    heap[0].total += 1;
    qsort(heap, classesSize, sizeof(Class), compare);
}

double totalRatio = 0.0;
for( i = 0; i < classesSize; i++){
    totalRatio += (double)heap[i].pass / heap[i].total; 
}
double averageRatio = totalRatio/classesSize;

free(heap);

return averageRatio;

}