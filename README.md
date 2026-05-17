# Cryptography — PRESENT Cipher

An implementation of the [PRESENT](https://www.iacr.org/archive/ches2007/47270450/47270450.pdf) lightweight block cipher, a standard designed for highly constrained environments (RFID, sensor nodes).

Two implementations are provided:

| File | Language | Notes |
|------|----------|-------|
| `main.c` | C | Standalone implementation, compile and run directly |
| `main.py` | Python | Streamlit web UI — visualizes encryption steps in the browser |

## Run

**C:**
```bash
gcc main.c -o present && ./present
```

**Python (Streamlit UI):**
```bash
pip install streamlit
streamlit run main.py
```

## What is PRESENT?

PRESENT is an ultra-lightweight 64-bit block cipher with an 80-bit key, standardized in ISO/IEC 29192-2. It uses a substitution-permutation network (SPN) with 31 rounds and is designed to run efficiently on hardware with minimal gate count.

## License

MIT
