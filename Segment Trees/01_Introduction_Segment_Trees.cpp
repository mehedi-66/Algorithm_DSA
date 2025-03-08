/*
    ************ Segment Trees ************
     You are given array and Q queries For each Query find out minimum

        arr[7] = {1, 0, 3, 2, 4, 2, 1}
            index 0  1  2  3  4  5  6

        Q = 3

        1 3 => 0
        3 6 => 1
        2 5 => 2

    Brute forces Solution :

        for(int i = 0; i < q; i++)
        {
            cin >> L >> R;
            min = a[L];
            for( j = L; j <= R; j++)
            {
                min = min(min, a[j]);
            }
        }

    TC => O( Q x (R-L + 1) )

    But given all Query  0  n-1
                         0  n-1
                         0  n-1

        TC => O(Q x N )

        almost O(N^2)




    Now Segment come into the picture

    Segment Tree O( log n)


    Useful things of segment tree:
        1) Rang query in given range
        2) find out Max and Min
        3) sum of given range
        4) we can update in the index value and track





Watch : => 

https://www.youtube.com/watch?v=-dUiRtJ8ot0

*/
using System;

class SegmentTree
{
    private int[] tree;
    private int n;

    // Build the segment tree
    public SegmentTree(int[] arr)
    {
        n = arr.Length;
        tree = new int[4 * n];  // Allocate sufficient space
        Build(arr, 0, 0, n - 1);
    }

    private void Build(int[] arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start]; // Leaf node
        }
        else
        {
            int mid = (start + end) / 2;
            Build(arr, 2 * node + 1, start, mid);
            Build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = Math.Min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Range minimum query
    public int Query(int left, int right)
    {
        return Query(0, 0, n - 1, left, right);
    }

    private int Query(int node, int start, int end, int left, int right)
    {
        if (right < start || left > end) return int.MaxValue; // No overlap
        if (left <= start && end <= right) return tree[node]; // Complete overlap

        int mid = (start + end) / 2;
        int leftMin = Query(2 * node + 1, start, mid, left, right);
        int rightMin = Query(2 * node + 2, mid + 1, end, left, right);
        return Math.Min(leftMin, rightMin);
    }
}

class Program
{
    static void Main()
    {
        int[] arr = { 1, 3, 5, 7, 9, 11, 15 };
        SegmentTree segTree = new SegmentTree(arr);

        int[,] queries = { { 1, 4 }, { 2, 5 }, { 0, 6 } };
        
        foreach (var query in queries)
        {
            Console.WriteLine(segTree.Query(query[0], query[1]));
        }
    }
}
