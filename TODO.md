# ✅ Sensor Network Simulator - Smart Building System

## ✅ Milestone 1: Project Structure
- [x] Set up CMake-based project with modular directories
- [x] Create broker, sensor, and common modules
- [x] Add Boost and shared utilities (e.g. NetworkUtils)
- [x] Create SensorNodeBase and generate sensor UUIDs
- [x] Add basic sensors: temperature, motion, sound

---

## ✅ Milestone 2: Sensor Communication
- [x] Implement `sendDataToBroker()` TCP client in sensors
- [x] Create basic `BrokerServer` to accept connections
- [x] Use Boost.Asio async accept + async read
- [x] Serialize sensor data as JSON-style string

---

## ✅ Milestone 3: Message Handling
- [x] Accept sensor connections
- [x] Route messages to consumers 
- [x] Log incoming data with timestamp
- [x] Parse JSON and extract sensor metadata
- [x] Include sensor type and value in broker log
- [ ] Sanitize inputs before accepting payload *  ← (input validation)
- [ ] Check client source IP or certificate (when secure mode enabled) *  ← (origin validation)

---

## 🔜 Milestone 4: Smart Building Features (Core Logic)
- [ ] Add CO₂ and humidity sensors
- [ ] Simulate HVAC control logic based on thresholds
- [ ] Store room-level sensor states in broker memory
- [ ] Track occupancy based on motion sensors
- [ ] Trigger auto-disable HVAC if window sensors report open
- [ ] Log sensor uptime and dropouts *
- [ ] Authenticate sensor clients using token or public key *  ← (authentication)
- [ ] Hash/log sensor ID with message to detect spoofing *
- [ ] Add anomaly detection logic (e.g. temp too high when HVAC is active)

---

## 🔜 Milestone 5: Consumer Architecture
- [ ] Define `IMessageConsumer` interface
- [ ] Implement `LoggerConsumer` (file log)
- [ ] Implement `AlertConsumer` (e.g. stdout warning if threshold exceeded)
- [ ] Add `SecurityConsumer` to detect conflicting sensor behavior *
- [ ] Route incoming data to all consumers via observer pattern
- [ ] Record last-seen timestamp per sensor and flag stale sources *

---

## 🔜 Milestone 6: Configuration & Resilience
- [ ] Create `Configuration` class to define system-wide settings (e.g. broker host/port, unit system)
- [ ] Enable per-sensor config overrides (e.g. calibration values)
- [ ] Add environment-specific settings loader (e.g. prod vs test)
- [ ] Add secure mode toggle to enforce stricter policies *
- [ ] Retry connections on failure with exponential backoff
- [ ] Prevent malformed data from crashing broker *

---

## 🔜 Milestone 7: UI / Visual Layer
- [ ] Optional: CLI dashboard with sensor values and alerts
- [ ] Optional: WebSocket endpoint for live updates
- [ ] Optional: Historical graphing (temp, CO₂) via CSV export or browser frontend

---

## 🔐 Cybersecurity-Specific Goals (all items above marked with `*`)
- Input validation (malformed or malicious payloads)
- Client authentication (e.g. tokens or certs)
- Origin verification (IP, hostname, etc.)
- Message integrity checks (hashing, signatures)
- Timestamp validation and message freshness
- Secure mode toggle (e.g. disable unauthenticated sensors)
- Alert routing based on trust level of sensor