# PRESENT Cipher

Two implementations of the [PRESENT](https://www.iacr.org/archive/ches2007/47270450/47270450.pdf) lightweight block cipher — a standard designed for highly resource-constrained environments (RFID tags, embedded sensors, IoT devices).

---

## What is PRESENT?

PRESENT is a 64-bit block cipher with an 80-bit key, standardized in **ISO/IEC 29192-2**. It uses a substitution-permutation network (SPN) with 31 rounds. Its design goal is extreme hardware efficiency — it can be implemented with a very small gate count while maintaining strong security properties.

**Core operations per round:**
1. **AddRoundKey** — XOR the state with the round subkey
2. **SBoxLayer** — apply 4-bit S-box to each nibble of the 64-bit state (16 nibbles)
3. **PBoxLayer** — apply the bit permutation P to the full 64-bit state

The final round skips the P-box and applies only the last subkey (whitening).

---

## Implementations

### `main.c` — C Implementation

A complete, standalone implementation with full key scheduling, encryption, and decryption.

```bash
gcc main.c -o present
./present
```

Enter the 64-bit plaintext in hexadecimal (16 hex chars) when prompted.

**Internals:**
- Uses a packed `byte` struct with two 4-bit nibbles to represent the 64-bit state as 8 bytes
- Key scheduling: generates 32 subkeys from an 80-bit master key using the PRESENT schedule (61-bit rotation, S-box on MSN, round counter XOR)
- Permutation and inverse permutation are implemented by moving one bit at a time per the permutation table P
- Memory-safe: all heap allocations are freed after use

### `main.py` — Python + Streamlit UI

An interactive web app for encrypting and decrypting with PRESENT.

```bash
pip install streamlit
streamlit run main.py
```

Opens a browser UI at `http://localhost:8501`. Enter plaintext and key in hex, switch between encrypt/decrypt modes via the sidebar.

---

## Algorithm Reference

| Parameter | Value |
|-----------|-------|
| Block size | 64 bits |
| Key size | 80 bits |
| Rounds | 31 |
| S-box | 4-bit, `{C,5,6,B,9,0,A,D,3,E,F,8,4,7,1,2}` |
| Standard | ISO/IEC 29192-2 |

**Key schedule (80-bit):**
1. Extract the high 64 bits as the current subkey
2. Rotate the full 80-bit key left by 61 bits
3. Apply S-box to the most significant nibble
4. XOR bits `k19..k15` with the round counter

---

## License

MIT
