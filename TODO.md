# Sensor Network Simulator – Milestones

## ✅ Milestone 1: Project Scaffolding
- [x] Git repository initialized
- [x] Project folder structure created
- [x] CMake build system working
- [x] Broker module stub implemented

## 🚧 Milestone 2: Sensor Node Module
- [x] Create virtual sensor classes (Temperature, Sound, Motion)
- [x] Simulate periodic data generation
- [x] Use Boost.Asio to send data to broker

## 🚧 Milestone 3: Message Broker Expansion
- [x] Accept sensor connections
- [ ] Route messages to consumers
- [ ] Log incoming data

## 🚧 Milestone 4: Security Layer
- [ ] Add TLS/SSL encryption with OpenSSL
- [ ] Implement simple token authentication
- [ ] Detect and log spoof/replay attacks

## 🚧 Milestone 5: Frontend Interface (Optional)
- [ ] Qt dashboard to view live sensor updates
- [ ] Controls to start/stop simulation

## 🚧 Milestone 6: Final Polish
- [ ] Add unit tests
- [ ] Add build scripts
- [ ] Write user documentation# Sensor Network Simulator – Milestones

## ✅ Milestone 1: Project Scaffolding
- [x] Git repository initialized
- [x] Project folder structure created
- [x] CMake build system working
- [x] Broker module stub implemented
- [x] Version control connected to GitHub

## 🚧 Milestone 2: Sensor Node Module
- [ ] Create virtual sensor classes (e.g., TemperatureSensor)
- [ ] Simulate periodic data generation
- [ ] Send sensor data via Boost.Asio to the broker
- [ ] Implement multithreaded simulation

## 🚧 Milestone 3: Message Broker Expansion
- [ ] Accept and manage sensor connections
- [ ] Parse and log incoming data
- [ ] Route data to the anomaly detector module

## 🚧 Milestone 4: Frontend Interface (Optional)
- [ ] Build a Qt dashboard to show live sensor updates
- [ ] Display connection status and alerts
- [ ] Allow start/stop/reset controls from UI

## 🚧 Milestone 5: Cybersecurity Features
- [ ] Enable TLS encryption for sensor-broker communication (OpenSSL + Boost.Asio)
- [ ] Implement authentication (token or PSK per sensor)
- [ ] Add basic intrusion detection: rate limiting, replay detection, spoof protection
- [ ] Create a "malicious node" for simulated attacks (flooding, replay, etc.)
- [ ] Log security events separately
- [ ] Collaborator to generate threat report script from logs

## 🚧 Milestone 6: Final Polish & Deployment
- [ ] Add unit tests (sensors, broker, security)
- [ ] Add `.gitignore`, build scripts, and documentation
- [ ] Add systemd service files or launch scripts (Linux)
- [ ] Create project README and contributor guidelines
