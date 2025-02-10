typedef struct {
    int pass, total;
    double benefit;
} Class;

double CalculateBenefit( int pass, int total ) {
    return ( ( double ) ( pass + 1 ) / ( total + 1 ) ) - ( ( double ) pass / total );
}

void Swap( Class *a, Class *b ) {
    Class temp = *a;
    *a = *b;
    *b = temp;
}

void HeapifyUp( Class *heap, int index ) {
    while ( index > 0 ) {
        int parent = ( index - 1 ) / 2;
        if ( heap[ parent ].benefit >= heap[ index ].benefit)
            break;
        Swap( &heap[ parent ], &heap[ index ] );
        index = parent;
    }
}

void HeapifyDown( Class *heap, int size, int index ) {
    while ( 1 ) {
        int left = 2 * index + 1, right = 2 * index + 2, largest = index;
        if ( left < size && heap[ left ].benefit > heap[ largest ].benefit )
            largest = left;
        if ( right < size && heap[ right ].benefit > heap[ largest ].benefit)
            largest = right;
        if ( largest == index )
            break;
        Swap( &heap[ index ], &heap[ largest ] );
        index = largest;
    }
}

void PushHeap( Class *heap, int *size, int pass, int total ) {
    heap[ *size ] = ( Class ){ pass, total, CalculateBenefit( pass, total ) };
    HeapifyUp( heap, ( *size )++ );
}

Class PopHeap( Class *heap, int *size ) {
    Class top = heap[ 0 ];
    heap[ 0 ] = heap[--( *size ) ];
    HeapifyDown( heap, *size, 0 );
    return top;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    static Class heap[ 100000 ];
    int heapSize = 0;
    int i;
    for (i = 0; i < classesSize; i++) {
        PushHeap( heap, &heapSize, classes[ i ][ 0 ], classes[ i ][ 1 ] );
    }

    while ( extraStudents-- > 0 ) {
        Class topClass = PopHeap( heap, &heapSize );
        topClass.pass++;
        topClass.total++;
        topClass.benefit = CalculateBenefit( topClass.pass, topClass.total );
        PushHeap( heap, &heapSize, topClass.pass, topClass.total );
    }

    double totalRatio = 0.0;
    for ( i = 0; i < heapSize; i++ ) {
        totalRatio += ( double )heap[ i ].pass / heap[ i ].total;
    }

    return totalRatio / classesSize;
}