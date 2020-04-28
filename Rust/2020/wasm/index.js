const rust = import('./pkg/wasm')

function isPrime(n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (let i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

function nthPrime(nth)
{
    if (nth == 0) return 0;
    if (nth == 1) return 2;

    let total = 1;

    for (let i = 3; ; i += 2) {
        if (isPrime(i)) {
            total++;
            if (total == nth) {
                return i;
            }
        }
    }
}

rust.then(func => {
    func.create_stuff()
    func.run_alert("JavaScript")
    document.querySelector('#nth_prime_button').addEventListener('click', function () {
        let nth = document.querySelector('#nth_prime_input').value

        let js_t0 = performance.now()
        let js_nth = nthPrime(nth)
        let js_t1 = performance.now()

        let wasm_t0 = performance.now()
        let wasm_nth = func.nth_prime(nth);
        let wasm_t1 = performance.now()

        document.querySelector('#nth_prime_result').innerHTML = `${nth}th Prime : ${wasm_nth} [ ${js_nth} ]`

        document.querySelector('#performance_wasm').innerHTML = `WASM Runtime: ${wasm_t1 - wasm_t0} milliseconds`
        document.querySelector('#performance_js').innerHTML = `JS Runtime: ${js_t1 - js_t0} milliseconds`
    })
})
