/* general custom soring */
sort(idx.begin(), idx.end(), [](const auto& a, const auto& b){
    return compare(a, b);
});

/* sorting array idx according to array A */
sort(idx.begin(), idx.end(), [&A](const auto& a, const auto& b){
    return compare(A[a], A[b]);
});

/* WARNING: compare method should be absolute, for example a < b instead of a <= b */
