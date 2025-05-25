```bash
aws configure
aws ec2 describe-instances --region us-east-1 --profile myprofile
aws ec2 start-instances --instance-ids i-0abcdef1234567890
aws ec2 stop-instances --instance-ids i-0abcdef1234567890
aws ec2 terminate-instances --instance-ids i-0abcdef1234567890
aws ec2 run-instances --image-id ami-0abcdef1234567890 --count 1 --instance-type t2.micro --key-name MyKeyPair --security-group-ids sg-0123456789abcdef0
aws ec2 create-security-group --group-name MySecurityGroup --description "My security group"
```